<h2><a href="https://codeforces.com/contest/2048/problem/B" target="_blank" rel="noopener noreferrer">2048B — Kevin and Permutation</a></h2>

| | |
|---|---|
| **Difficulty** | 900 |
| **Language** | PyPy 3-64 |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2048B](https://codeforces.com/contest/2048/problem/B) |

## Topics
`constructive algorithms` `greedy`

---

## Problem Statement

<div class="header"><div class="title">B. Kevin and Permutation</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p> </p><p>Kevin is a master of permutation-related problems. You are taking a walk with Kevin in Darkwoods, and during your leisure time, he wants to ask you the following question.</p><p>Given two positive integers $$$ n $$$ and $$$ k $$$, construct a permutation$$$^{\text{∗}}$$$ $$$ p $$$ of length $$$ n $$$ to minimize the sum of the minimum values of all subarrays$$$^{\text{†}}$$$ of length $$$ k $$$. Formally, you need to minimize</p><p>$$$$$$ \sum_{i=1}^{n-k+1}\left( \min_{j=i}^{i+k-1} p_j\right). $$$$$$</p><div class="statement-footnote"><p>$$$^{\text{∗}}$$$A permutation of length $$$n$$$ is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array), and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$ but there is $$$4$$$ in the array). </p><p>$$$^{\text{†}}$$$An array $$$a$$$ is a subarray of an array $$$b$$$ if $$$a$$$ can be obtained from $$$b$$$ by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. Two subarrays are considered different if the sets of <span class="tex-font-style-bf">positions</span> of the deleted elements are different. </p></div></div><div class="input-specification"><div class="section-title">Input</div><p>Each test consists of multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^3$$$).</p><p>The only line of each test case contains two integers $$$ n $$$ and $$$ k $$$ ($$$ 1\le k\le n\le 10^5 $$$).</p><p>It is guaranteed that the sum of $$$ n $$$ over all test cases doesn't exceed $$$ 10^5 $$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output $$$ n $$$ integers on a single line — the permutation $$$ p $$$ you constructed.</p><p>If there are multiple answers, you can print any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0028059604033284" id="id00839081293511434" class="input-output-copier">Copy</div></div><pre id="id0028059604033284">3
4 2
6 1
8 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006762861748428849" id="id0031150763681957083" class="input-output-copier">Copy</div></div><pre id="id006762861748428849">3 1 2 4
5 2 1 6 4 3
4 6 2 8 3 1 5 7
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, with $$$ k=2 $$$, consider all subarrays of length $$$ 2 $$$: the minimum value of $$$ p_1,p_2 $$$ is $$$ 1 $$$, the minimum value of $$$ p_2,p_3 $$$ is $$$ 1 $$$, and the minimum value of $$$ p_3,p_4 $$$ is $$$ 2 $$$. The sum $$$ 1+1+2=4 $$$ is the smallest among all possible permutations.</p><p>In the second test case, all subarrays of length $$$ 1 $$$ have minimum values of $$$ 5, 2, 1, 6, 4, 3 $$$, and the sum $$$ 5+2+1+6+4+3=21 $$$ is proven to be the smallest.</p></div>