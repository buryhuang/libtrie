#include <string>

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int idx = 0; idx < 26; idx++) {
			links_[idx] = nullptr;
		}
	}

	bool containsCh(char ch)
	{
		int index = ch - 'a';
		return links_[index] == nullptr ? false : true;
	}

	TrieNode * getNode(char ch) {
		int index = ch - 'a';
		return links_[index];
	}

	void putCh(char ch) {
		int index = ch - 'a';
		links_[index] = new TrieNode();
	}

	bool isEnd() {
		return isEnd_;
	}

	void setEnd() {
		isEnd_ = true;
	}

private:
	TrieNode* links_[26];
	bool isEnd_;

};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(std::string word) {
		TrieNode * curr = root;
		for (int idx = 0; idx < word.size(); idx++)
		{
			char ch = word[idx];
			if (!curr->containsCh(ch)) {
				curr->putCh(ch);
			}
			curr = curr->getNode(ch);
		}
		curr->setEnd();
	}

	// Returns if the word is in the trie.
	bool search(std::string word) {
		TrieNode * curr = root;
		for (int idx = 0; idx < word.size(); idx++) {
			if (curr->isEnd()) {
				break;
			}
			else {
				curr = curr->getNode(word[idx]);
			}
		}
		return curr->isEnd() ? false : true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(std::string prefix) {
		return search(prefix);
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");