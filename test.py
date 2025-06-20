import random
import itertools

def brute_solve(d, l, r):
    n = len(d)
    for assignment in itertools.product([0,1], repeat=d.count(-1)):
        d_copy = d[:]
        it = iter(assignment)
        for i in range(n):
            if d_copy[i] == -1:
                d_copy[i] = next(it)
        h = 0
        ok = True
        for i in range(n):
            h += d_copy[i]
            if not (l[i] <= h <= r[i]):
                ok = False
                break
        if ok:
            return d_copy
    return None

def greedy_solve(d, l, r):
    n = len(d)
    # compute suffix min of ceilings
    suf_min = [float('inf')] * (n+1)
    for i in range(n-1, -1, -1):
        suf_min[i] = min(suf_min[i+1], r[i])
    h = 0
    res = d[:]
    for i in range(n):
        if res[i] == -1:
            res[i] = 1 if h < suf_min[i] else 0
        h += res[i]
        # forgot upper bound check
        if not (l[i] <= h <= r[i]):
            return None
    return res

def validate_solution(sol, l, r):
    """Return True if sol is a valid flight program for ranges l, r."""
    if sol is None:
        return False
    h = 0
    for i, di in enumerate(sol):
        h += di
        if not (l[i] <= h <= r[i]):
            return False
    return True

def find_counterexample(trials=10000, max_n=8):
    for _ in range(trials):
        n = random.randint(1, max_n)
        d = [random.choice([-1,0,1]) for _ in range(n)]
        # generate random l, r with 0 <= l <= r <= n
        l = [random.randint(0, n) for _ in range(n)]
        r = [random.randint(0, n) for _ in range(n)]
        for i in range(n):
            if l[i] > r[i]:
                l[i], r[i] = r[i], l[i]

        brute = brute_solve(d, l, r)
        greedy = greedy_solve(d, l, r)
        greedy_valid = validate_solution(greedy, l, r)
        brute_exists = (brute is not None)

        # Cases where greedy is incorrect:
        # 1) greedy returns a solution but it's invalid
        # 2) greedy returns None but brute found a solution
        if (greedy is not None and not greedy_valid) or (greedy is None and brute_exists):
            print("Counterexample found:")
            print("n =", n)
            print("d =", d)
            print("l =", l)
            print("r =", r)
            print("Brute:", brute)
            print("Greedy:", greedy, "(valid? {})".format(greedy_valid))
            return

    print("No counterexample found in", trials, "trials.")

# Run the search
find_counterexample()
