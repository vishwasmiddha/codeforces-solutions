<h2><a href="https://codeforces.com/contest/2043/problem/B" target="_blank" rel="noopener noreferrer">2043B — Digits</a></h2>

| | |
|---|---|
| **Difficulty** | 1100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2043B](https://codeforces.com/contest/2043/problem/B) |

## Topics
`math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">B. Digits</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Artem wrote the digit $$$d$$$ on the board exactly $$$n!$$$ times in a row. So, he got the number $$$dddddd \dots ddd$$$ (exactly $$$n!$$$ digits).</p><p>Now he is curious about which <span class="tex-font-style-bf">odd</span> digits from $$$1$$$ to $$$9$$$ divide the number written on the board.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$t$$$ ($$$1 \le t \le 100$$$) — the number of test cases. The next $$$t$$$ test cases follow.</p><p>Each test case consists of a single line containing two integers $$$n$$$ and $$$d$$$ ($$$2 \le n \le 10^9$$$, $$$1 \le d \le 9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the odd digits in ascending order that divide the number written on the board.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006375820119006879" id="id00048081161438342734" class="input-output-copier">Copy</div></div><pre id="id006375820119006879"><div class="test-example-line test-example-line-even test-example-line-0">3</div><div class="test-example-line test-example-line-odd test-example-line-1">2 6</div><div class="test-example-line test-example-line-even test-example-line-2">7 1</div><div class="test-example-line test-example-line-odd test-example-line-3">8 5</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009105799794089451" id="id0030348578894913136" class="input-output-copier">Copy</div></div><pre id="id009105799794089451">1 3 
1 3 7 9 
1 3 5 7 9 
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>The factorial of a positive integer $$$n$$$ ($$$n!$$$) is the product of all integers from $$$1$$$ to $$$n$$$. For example, the factorial of $$$5$$$ is $$$1 \cdot 2 \cdot 3 \cdot 4 \cdot 5 = 120$$$.</p></div>