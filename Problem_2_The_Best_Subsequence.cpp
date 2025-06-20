#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll MOD = 1000000007;
 
// Fast exponentiation mod MOD.
ll modExp(ll base, ll exp) {
    ll res = 1 % MOD;
    base %= MOD;
    while(exp){
        if(exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
 
// Structure to represent an interval [l, r] with a constant binary value (0 or 1)
struct Interval {
    ll l, r;
    int val;
};
 
// --- Step 1. Process flip updates to build the final string (in compressed form) ---
// The string S has length N (up to 1e9) and is initially all 0’s.
// Each flip update on [l, r] toggles bits in that range.
// We use a “difference‐array” (via events) so that we store only the positions where flips occur.
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int M, Q;
    ll N;
    cin >> N >> M >> Q;
    // We'll record events: at position l, toggle; at position r+1, toggle.
    // Use a map so that only O(M) positions are stored.
    map<ll,int> events;
    for (int i = 0; i < M; i++){
        ll L, R; 
        cin >> L >> R;
        events[L] ^= 1;
        if(R+1 <= N) events[R+1] ^= 1;
    }
    // Make sure positions 1 and N+1 appear.
    events[1];
    events[N+1];
 
    // Now sweep through events in increasing order to build intervals.
    vector<Interval> segs;
    ll prev = 1;
    int cur = 0;
    for(auto &e : events){
        ll pos = e.first;
        if(pos > prev){
            // interval [prev, pos-1] has value = cur mod2
            segs.push_back({prev, pos-1, cur & 1});
        }
        cur ^= e.second; // toggle if needed
        prev = pos;
    }
    // Now segs holds the entire final string S in O(M) intervals.
 
    // --- Step 2. Build a vector of ones–intervals ---
    // These intervals are exactly those intervals from segs with value==1.
    vector<Interval> ones;
    for(auto &itv : segs){
        if(itv.val == 1)
            ones.push_back(itv);
    }
    // (ones is sorted by l.)
 
    // --- Step 3. Query simulation ---
    // For each query we are given [l, r, k].
    // From the final S we want the lexicographically maximum subsequence (of length k)
    // from S[l..r]. (Then we output its binary–number value modulo MOD.)
    //
    // It is known that the following greedy algorithm yields that subsequence:
    //
    //   Let t = 1 (the pick index, 1–indexed), pos = l.
    //   For each pick t (with remaining picks rem = k - t + 1),
    //     define allowed = r - rem + 1.
    //     In the current window [pos, allowed] if there is any 1 then choose the leftmost one,
    //     otherwise (if no 1 is available) choose a 0 (i.e. “skip” a position).
    //   (Each pick chosen becomes the t‑th bit of the answer; the first pick has weight 2^(k–1), the last 2^0.)
    //
    // To “simulate” this without iterating pick–by–pick we “jump” over blocks.
    //
    // In our simulation we “extract” the union of ones–intervals in [l, r] using binary search on the global ones vector.
    auto getOnesInRange = [&](ll L, ll R) -> vector<pair<ll,ll>> {
        vector<pair<ll,ll>> res;
        // Binary–search: find the first ones–interval with r >= L.
        int lo = 0, hi = (int)ones.size()-1, startIdx = ones.size();
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(ones[mid].r >= L){
                startIdx = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        for (int i = startIdx; i < ones.size(); i++){
            if(ones[i].l > R) break;
            ll a = max(L, ones[i].l);
            ll b = min(R, ones[i].r);
            if(a <= b) res.push_back({a,b});
        }
        return res;
    };
 
    // The simulation returns the binary value (mod MOD) of the greedy subsequence.
    // We simulate in “pick–index space”: picks 1..k.
    // At pick t, with rem = k-t+1 the allowed range is [pos, r - rem + 1].
    // If a 1 is available (from our union of ones–intervals) in that window,
    // then we can take a block of consecutive ones from that ones–block.
    // Their combined contribution is computed using a geometric series.
    // Otherwise, we “jump” a block of zeros (which contribute 0) – here we compute how many picks we must take
    // until the “allowed” boundary grows far enough that the next one becomes available.
    auto solveQuery = [&](ll l, ll r, ll k) -> ll {
        vector<pair<ll,ll>> onesUnion = getOnesInRange(l, r);
        int idx = 0; // pointer into onesUnion
        ll pos = l; // next global index in [l, r] to consider
        ll pick = 1; // current pick index (1-indexed); total picks = k
        ll ans = 0;
        // Greedy simulation with block–jumps:
        // For pick index pick, rem = k - pick + 1 and allowed = r - rem + 1.
        while(pick <= k){
            ll rem = k - pick + 1; 
            ll allowed = r - rem + 1;  // we can only pick from [pos, allowed] if we want a 1
            // Advance onesUnion pointer if the current block is entirely before pos.
            while(idx < (int)onesUnion.size() && onesUnion[idx].second < pos)
                idx++;
            // Determine the next candidate 1 (if any) in [pos, r]:
            ll candidate = r+1; // if none exists
            if(idx < (int)onesUnion.size()){
                if(onesUnion[idx].first > pos)
                    candidate = onesUnion[idx].first;
                else
                    candidate = pos; // we are inside a ones block
            }
            if(candidate <= allowed){
                // We are in a ones–block.
                // Let block = [blockStart, blockEnd] be the current ones block (its intersection with [l, r]).
                ll blockStart = candidate;
                ll blockEnd = r;
                if(idx < (int)onesUnion.size()){
                    blockEnd = onesUnion[idx].second;
                    if(blockEnd > r) blockEnd = r;
                }
                // In a ones block, if we can pick one at the current pick then because after each pick
                // the allowed boundary shifts (and rem decreases) we can take ALL consecutive ones in the block.
                // So we let tBlock = min(rem, blockEnd - blockStart + 1).
                ll tBlock = min(rem, blockEnd - blockStart + 1);
                // The ones chosen occupy picks [pick, pick+tBlock-1].
                // Their contribution is: sum_{i=0}^{tBlock-1} 2^(k - (pick+i))
                // = 2^(k - pick + 1) - 2^(k - pick - tBlock + 1)  (mod MOD)
                ll term1 = modExp(2, k - pick + 1);
                ll term2 = modExp(2, k - pick - tBlock + 1);
                ll contrib = (term1 - term2) % MOD;
                if(contrib < 0) contrib += MOD;
                ans = (ans + contrib) % MOD;
                pick += tBlock;
                pos = blockStart + tBlock; // we "consume" these positions
                if(idx < (int)onesUnion.size() && pos > onesUnion[idx].second)
                    idx++;
            } else {
                // No 1 is available in [pos, allowed] so we must pick a 0.
                // Rather than doing one pick at a time, we “jump” zeros.
                // When we take a zero pick, pos increases by 1 and pick increases by 1.
                // We want to know how many zeros we can take until the allowed boundary (which is r - (k - pick) + 1) reaches the next candidate.
                ll nextOne = candidate; // candidate > allowed here
                // For current pick, allowed = r - rem + 1.
                // For future pick j (j picks later) the allowed value becomes: r - (rem - j) + 1 = r - rem + j + 1.
                // We want the minimal j such that r - rem + j + 1 >= nextOne.
                ll need = nextOne - (r - rem + 1);
                if(need < 1) need = 1; // at least one pick
                // Also we cannot jump past the gap available in [pos, nextOne).
                ll gap = nextOne - pos;
                ll tJump = min({rem, need, gap});
                // These zero–picks add no contribution.
                pick += tJump;
                pos += tJump;
            }
        }
        return ans % MOD;
    };
 
    // --- Process queries ---
    for (int i = 0; i < Q; i++){
        ll l, r, k;
        cin >> l >> r >> k;
        // It is guaranteed 1 <= k <= (r-l+1)
        ll res = solveQuery(l, r, k);
        cout << res % MOD << "\n";
    }
 
    return 0;
}
