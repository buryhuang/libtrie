#include "TrieTree.hpp"

int main()
{
	// Your Trie object will be instantiated and called as such:
	Trie trie;
	trie.insert("somestring");
	printf("%s\n", trie.search("key") ? "true" : "false");
	printf("%s\n", trie.startsWith("key") ? "true" : "false");

	printf("%s\n", trie.search("some") ? "true" : "false");
	printf("%s\n", trie.startsWith("some") ? "true" : "false");

	printf("%s\n", trie.search("somestring") ? "true" : "false");
	printf("%s\n", trie.startsWith("somestring") ? "true" : "false");

	// insert("hello"),search("hell"),search("helloa"),search("hello"),startsWith("hell"),startsWith("helloa"),startsWith("hello")
	// [false,false,true,true,false,true]
	trie.insert("hello");
	printf("%s\n", trie.startsWith("helloa") ? "true" : "false");

	// insert("ab"),search("abc"),search("ab"),startsWith("abc"),startsWith("ab"),insert("ab"),search("abc"),startsWith("abc"),insert("abc"),search("abc"),startsWith("abc")
	// [false,true,false,true,false,false,true,true]
	trie.insert("ab");
	trie.insert("abc");
	printf("%s\n", trie.startsWith("abc") ? "true" : "false");
	return 0;
}