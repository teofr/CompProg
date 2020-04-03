import sys

def advance(indices, N):
  indices.sort(key = lambda idx: N[idx[0]], reverse = True)
  count = 0
  while count < len(indices) and N[indices[count][0]] == N[indices[0][0]]:
    count += 1
  return indices[0:count]

def solution(N, K):
  possible_solutions = list(zip(range(len(N)-K+1), range(len(N)-K+1)))
  
  so_far = 0
  
  while so_far < K and len(possible_solutions) > 1:
    print(possible_solutions)
    possible_solutions = advance(possible_solutions, N)
  ans = possible_solutions[0][1]
  return N[ans:ans+K]


def main():
  """Read from stdin, solve the problem, write answer to stdout."""
  input = sys.stdin.readline().split()
  N = [int(x) for x in input[0].split(",")]
  K = int(input[1])
  sys.stdout.write(",".join([str(i) for i in solution(N, K)]))


if __name__ == "__main__":
  main()
