<h2><a href="https://codeforces.com/contest/2172/problem/A" target="_blank" rel="noopener noreferrer">2172A — ASCII Art Contest</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2172A](https://codeforces.com/contest/2172/problem/A) |

## Topics
`implementation`

---

## Problem Statement

<div class="header"><div class="title">A. ASCII Art Contest</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Three leading AI-powered creative assistants—Gemini, ChatGPT, and Claude—enter the first ever ASCII Art Contest, where they must impress a panel of human judges with their text-based masterpieces.</p><p>Each participant receives a score between 80 and 100 (inclusive). The organizers want to announce the final standing only if the judges' opinions are "close enough"; otherwise, they will ask the judges to reconsider.</p><p>Given the three integer scores of Gemini, ChatGPT, and Claude, determine the contest result:</p><ul> <li> If the maximum score and the minimum score differ by at least 10 points, print <span class="tex-font-style-tt">check again</span> (the judging seems inconsistent, so the panel must re-evaluate). </li><li> Otherwise, print <span class="tex-font-style-tt">final X</span>, where <span class="tex-font-style-tt">X</span> is the median of the three scores (the score that would be in the middle if all three were sorted in non-decreasing order). </li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>A single line contains three integers $$$g, c, \ell$$$, representing the scores of Gemini, ChatGPT, and Claude respectively.</p><ul> <li> $$$80\le g, c, \ell \le 100$$$ </li></ul></div><div class="output-specification"><div class="section-title">Output</div><p>Print the required answer in a line.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0049298808595474697" id="id007349880554009125" class="input-output-copier">Copy</div></div><pre id="id0049298808595474697">88 94 95
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009210021243722739" id="id002583967473087714" class="input-output-copier">Copy</div></div><pre id="id009210021243722739">final 94
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009999354824515964" id="id003719331466679847" class="input-output-copier">Copy</div></div><pre id="id009999354824515964">100 80 81
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007392529687123923" id="id007942206325059116" class="input-output-copier">Copy</div></div><pre id="id007392529687123923">check again
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009808264286390083" id="id002865545091466981" class="input-output-copier">Copy</div></div><pre id="id009808264286390083">98 99 98
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0009853464051837091" id="id0014338933168458123" class="input-output-copier">Copy</div></div><pre id="id0009853464051837091">final 98
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0043464683165229445" id="id0014009342764082067" class="input-output-copier">Copy</div></div><pre id="id0043464683165229445">95 86 85
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007605535882250316" id="id003507460759493882" class="input-output-copier">Copy</div></div><pre id="id007605535882250316">check again
</pre></div></div></div>