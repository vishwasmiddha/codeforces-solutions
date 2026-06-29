<h2><a href="https://codeforces.com/contest/2154/problem/D" target="_blank" rel="noopener noreferrer">2154D — Catshock</a></h2>

| | |
|---|---|
| **Difficulty** | 1900 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2154D](https://codeforces.com/contest/2154/problem/D) |

## Topics
`constructive algorithms` `dfs and similar` `graphs` `trees` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">D. Catshock</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A cat lives on a tree with $$$n$$$ nodes. The cat starts on node $$$1$$$, and you live on node $$$n$$$. You are going to leave the cat a note written in the parkour language to help it reach you.</p><p>The parkour language has two types of instructions: </p><ul> <li> $$$1$$$ — This means that the cat should move to any adjacent node to it, if there are multiple options, it will pick one of them arbitrarily. If there are no adjacent nodes to it, then it will not move. </li><li> $$$2\,u$$$ — This means to destroy node $$$u$$$ and all adjacent edges to it. If the cat is currently on node $$$u$$$, it will die, so this should be avoided. If node $$$u$$$ was already destroyed, then nothing will happen. </li></ul><p><span class="tex-font-style-bf">Additionally, there cannot be two consecutive instances of the second instruction.</span></p><p>Unfortunately, the parkour language is ambiguous because the cat may have multiple options for each instance of the first instruction. So you should construct a sequence of instructions of length at most $$$3n$$$ so that if the cat follows them, it will end at node $$$n$$$, no matter what choices it makes. It can be proven that such a sequence exists for any tree.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. </p><p>The first line of each testcase contains an integer $$$n$$$ ($$$2 \le n \le 2 \cdot 10^5$$$) — the size of the tree.</p><p>Then $$$n - 1$$$ lines follow, each of them contains two integers $$$u$$$ and $$$v$$$ ($$$1 \le u,v \le n, u \ne v$$$) which describe a pair of vertices connected by an edge. It is guaranteed that the given graph is a tree and has no loops or multiple edges.</p><p>The sum of $$$n$$$ across all testcases does not exceed $$$2 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each testcase, output a single integer $$$k$$$ ($$$0 \le k \le 3n$$$) — the number of operations you will perform.</p><p>Then output $$$k$$$ lines of either of the following formats: </p><ul> <li> $$$1$$$ — make the cat move to an adjacent node if there are nodes adjacent to it. </li><li> $$$2\,u$$$ ($$$1 \le u \le n$$$) — delete node $$$u$$$ along with all adjacent edges </li></ul></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0007085732174298975" id="id008513007369809499" class="input-output-copier">Copy</div></div><pre id="id0007085732174298975"><div class="test-example-line test-example-line-even test-example-line-0">4</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">1 2</div><div class="test-example-line test-example-line-odd test-example-line-1">2 3</div><div class="test-example-line test-example-line-odd test-example-line-1">1 5</div><div class="test-example-line test-example-line-odd test-example-line-1">5 4</div><div class="test-example-line test-example-line-even test-example-line-2">2</div><div class="test-example-line test-example-line-even test-example-line-2">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">4</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">1 3</div><div class="test-example-line test-example-line-odd test-example-line-3">1 4</div><div class="test-example-line test-example-line-even test-example-line-4">6</div><div class="test-example-line test-example-line-even test-example-line-4">1 2</div><div class="test-example-line test-example-line-even test-example-line-4">1 3</div><div class="test-example-line test-example-line-even test-example-line-4">3 4</div><div class="test-example-line test-example-line-even test-example-line-4">4 5</div><div class="test-example-line test-example-line-even test-example-line-4">4 6</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009239690430658775" id="id0018897355780764047" class="input-output-copier">Copy</div></div><pre id="id009239690430658775">2
2 2
1

1
1

5
2 2
1
1
2 3
1

9
2 2
1
2 1
1
2 3
1
1
2 5
1</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>There are extra spaces between the output of different test cases only for <span class="tex-font-style-bf">clarity</span>, and the participants are not expected to print them.</p><p>The path of the cat in the first testcase is shown below.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/c37e026894cce61a0a49647f1cacf69fca6efe22.png" style="max-width: 100.0%;max-height: 100.0%;">   </center><p>It can be shown that this is the only possible path, and so the cat will always end at node $$$5$$$.</p><p>An example of a sequence of instructions that does not work for the first testcase is: $$$\mathtt{1}$$$, $$$\mathtt{2}$$$ $$$\mathtt{2}$$$. As the following may happen:</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/0b9189c63b2ada2a006bcf9b3ce12b9201c25c01.png" style="max-width: 100.0%;max-height: 100.0%;">   </center><p>Here the cat died at node $$$2$$$.</p></div>