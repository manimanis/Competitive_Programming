from typing import List


ALPHABET_SIZE = 26


def isPalindrome(s, start, end):
    i, j = start, end
    while j > i:
        if s[i] != s[j]:
            return False
        i, j = i+1, j-1
    return True


class TrieNode:
    def __init__(self, id=-1) -> None:
        self.children = {}
        self.pos = []
        self.id = id
        self.isLeaf = False

    @staticmethod
    def insert(root, key, id):
        crawl = root
        for level in range(len(key)-1, -1, -1):
            char = key[level]
            if char not in crawl.children:
                crawl.children[char] = TrieNode()

            if isPalindrome(key, 0, level):
                crawl.pos.append(id)

            crawl = crawl.children[char]

        crawl.id = id
        crawl.pos.append(id)
        crawl.isLeaf = True

    @staticmethod
    def search(root, key, id, res):
        crawl = root
        for level in range(len(key)):
            char = key[level]
            if crawl.id >= 0 and crawl.id != id and isPalindrome(key, level, len(key)-1):
                res.add((id, crawl.id))

            if char not in crawl.children:
                return

            crawl = crawl.children[char]

        for i in crawl.pos:
            if i == id:
                continue
            res.add((id, i))


def checkPalindromePair(arr: List[str]):
    root = TrieNode()
    for i in range(len(arr)):
        TrieNode.insert(root, arr[i], i)

    res = set([])
    for i in range(len(arr)):
        TrieNode.search(root, arr[i], i, res)

    return [[t0, t1] for t0, t1 in res]


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        res = checkPalindromePair(words)
        return res


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'palindromePairs',
                        prepare_out=lambda o: sorted(o),
                        prepare_res=lambda r: sorted(r))
