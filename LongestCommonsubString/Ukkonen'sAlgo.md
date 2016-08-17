

For length(String) = m:
* Time taken is O(m).
* Divided into m phases.

With an implicit suffixTree Ti constructed from a prefix of String S[1 .. i]:
* In phase i+1, tree Ti+1 is built from tree Ti.
* The **i+1 phase** deal with a String: S[1 .. i+1]. And for S[1 .. i+1], there are i+1 suffixes. Each Suffix has an extension. In other words: Phase i+1 has i+1 extension.

extension: phase i+1 with String S[1 .. i+1]
* For jth extension. Find the suffix S[j .. i]
* add the character i+1 to the path(branch)

For String xabxac, after phase 3, the tree looks like:
O   |-xab
    |-ab
    |-b
1. Now go to phase 4(i = 3).
2. 1st extension(j = 1) find S[1 .. 3] = xab
3. Add S[4] = x to the end of it.
4. Repeat...
5. 4th extension, find S[4] = x. Since x exist, do nothing. If S[4] doesn't exist, add S[4] to Root.</br>

A completion of all phase:

phase 1
O   |-x
phase 2
O   |-xa
    |-a
phase 3
O   |-xab
    |-ab
    |-b
phase 4
O   |-xabx
    |-abx
    |-bx
phase 5
O   |-xabxa
    |-abxa
    |-bxa
phase 6
O   |-xabxac    -> extension 4 ->   O   |-xa    |-bxac  ->
    |-abxac                                     |c
    |-bxac                             ...
    extension 5 -> O    |-xa    |-bxac   ->
                                |c
                        |a      |-bxac
                                |c
                        ...
    extension 6 -> O    |-xa    |-bxac
                                |c
                        |a      |-bxac
                                |c
                        |-bxac
                        |-c


### Some Tricks:
#### SUffix links
* O |-xabx
    |-abx
    |-bx
* Phase with String xabxa.
    * extension 1: Find xabx
    O   |-xabxc
        |-abx
        |-bx
    * extension 2: Find abx. With the help of links, time is saved









    <!--  -->