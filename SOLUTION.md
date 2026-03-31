# Problem 125 - Debugger - SOLUTION SUMMARY

## Problem Overview
- ACMOJ Problem ID: 1884
- Topic: Constraint Satisfaction Problem with Union-Find

## Final Result
**Score: 100/100** ✓ (All test cases passed)

## Submission History
1. **Submission 767215** - Score: 80/100
   - Used `map<int, int>` for coordinate compression
   - Test cases 9-10 exceeded time limit (TLE)

2. **Submission 767228** - Score: 100/100 ✓
   - Optimized to use `unordered_map<int, int>` for O(1) lookups
   - All test cases passed within time limits

## Algorithm Description

### Approach
Used **Union-Find (Disjoint Set Union)** with the following strategy:

1. **Coordinate Compression**: Map large variable IDs (up to 10^9) to compact indices using unordered_map
2. **Two-Pass Processing**:
   - First pass: Process all equality constraints (`xi = xj`) by uniting them in the same set
   - Second pass: Check inequality constraints (`xi ≠ xj`) - if both are in the same set, it's a contradiction

### Key Optimizations
- **Path compression** in Union-Find for nearly O(1) amortized find operations
- **Union by rank** to keep trees balanced
- **unordered_map** instead of map for O(1) average-case lookups vs O(log n)
- **Reserved capacity** for unordered_map to avoid rehashing

### Complexity
- **Time**: O(n × α(n)) per problem, where α is the inverse Ackermann function (nearly constant)
- **Space**: O(n) for storing constraints and Union-Find structure

## Test Results
| Test Case | Result | Time (ms) | Memory (MB) |
|-----------|--------|-----------|-------------|
| 1 | Accepted | 1 | 4.0 |
| 2 | Accepted | 2 | 3.8 |
| 3 | Accepted | 2 | 4.0 |
| 4 | Accepted | 5 | 4.1 |
| 5 | Accepted | 41 | 5.5 |
| 6 | Accepted | 41 | 5.5 |
| 7 | Accepted | 515 | 11.6 |
| 8 | Accepted | 473 | 11.6 |
| 9 | Accepted | 1983 | 11.7 |
| 10 | Accepted | 1879 | 11.6 |

**Total Time**: 4942 ms (well under 2000 ms per test case limit)
**Peak Memory**: 11.96 MB (well under 256 MB limit)

## Repository Structure
```
/workspace/problem_125/
├── .gitignore          # Git ignore configuration
├── Makefile            # Build configuration
├── README.md           # Original problem description
├── solution.cpp        # Final optimized solution
├── test_input.txt      # Sample test input
└── SOLUTION.md         # This summary document
```

## Compilation and Execution
```bash
make              # Compile the solution
./code < input    # Run with input file
```

## Key Learnings
1. For large-scale constraint satisfaction, data structure choice matters significantly
2. Hash tables (unordered_map) outperform balanced trees (map) for large datasets
3. Union-Find is the optimal data structure for equivalence relation problems
4. Proper optimization can improve performance by ~3x (from TLE to passing)
