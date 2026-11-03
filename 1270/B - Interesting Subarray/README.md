<h2><a href="https://codeforces.com/contest/1270/problem/B" target="_blank" rel="noopener noreferrer">1270B — Interesting Subarray</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1270B](https://codeforces.com/contest/1270/problem/B) |

## Topics
`constructive algorithms` `greedy` `math`

---

## Problem Statement

<div class="header"><div class="title">B. Interesting Subarray</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>For an array $$$a$$$ of integers let's denote its maximal element as $$$\max(a)$$$, and minimal as $$$\min(a)$$$. We will call an array $$$a$$$ of $$$k$$$ integers <span class="tex-font-style-bf">interesting</span> if $$$\max(a) - \min(a) \ge k$$$. For example, array $$$[1, 3, 4, 3]$$$ isn't interesting as $$$\max(a) - \min(a) = 4 - 1 = 3  \lt  4$$$ while array $$$[7, 3, 0, 4, 3]$$$ is as $$$\max(a) - \min(a) = 7 - 0 = 7 \ge 5$$$.</p><p>You are given an array $$$a$$$ of $$$n$$$ integers. Find some interesting <span class="tex-font-style-bf">nonempty</span> subarray of $$$a$$$, or tell that it doesn't exist.</p><p>An array $$$b$$$ is a subarray of an array $$$a$$$ if $$$b$$$ can be obtained from $$$a$$$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains integer number $$$t$$$ ($$$1 \le t \le 10\,000$$$). Then $$$t$$$ test cases follow.</p><p>The first line of each test case contains a single integer $$$n$$$ ($$$2\le n \le 2\cdot 10^5$$$) — the length of the array.</p><p>The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$0\le a_i \le 10^9$$$) — the elements of the array.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output "<span class="tex-font-style-tt">NO</span>" in a separate line if there is no interesting nonempty subarray in $$$a$$$. </p><p>Otherwise, output "<span class="tex-font-style-tt">YES</span>" in a separate line. In the next line, output two integers $$$l$$$ and $$$r$$$ ($$$1\le l \le r \le n$$$) — bounds of the chosen subarray. If there are multiple answers, print any.</p><p>You can print each letter in any case (upper or lower).</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008728073476536968" id="id002797107929763667" class="input-output-copier">Copy</div></div><pre id="id008728073476536968">3
5
1 2 3 4 5
4
2 0 1 9
2
2019 2020
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0020696239390875892" id="id0012198523688358454" class="input-output-copier">Copy</div></div><pre id="id0020696239390875892">NO
YES
1 4
NO
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the second test case of the example, one of the interesting subarrays is $$$a = [2, 0, 1, 9]$$$: $$$\max(a) - \min(a) = 9 - 0 = 9 \ge 4$$$.</p></div>