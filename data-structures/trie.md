# Trie

Implementation example of trie used to store words
```cpp
struct node{
  bool end;  // signifies a word ending at this character
  map<char,node*> next; // map to next node in the trie
}

node* root = new node();  // root of the trie
```

### Inserting a word
```cpp
void insert(string word){
  node* cur = root;
  for(auto& c : word){
    if (!cur->next[c])
      cur->next[c] = new node();
    cur = cur->next[c];
  }
  cur->end = true;
}
```

### Searching a word

Function to return true if a word exists in the trie.

```cpp
bool search(string word){
  node* cur = root;
  for(auto& c : word){
    if (!cur->next[c])
      return false;   // only difference in the loop
    cur = cur->next[c];
  }
  return (cur->end);
}
```

### Searching a word with wildcards

Suppose we allow `.` in the search string, e.g. `b..`
would return true if there are any 3-character string
starting with `b`. The difference here is that whenever
we encounter a `.`, we would have to branch to all possibilities,
so we have to use DFS-style recursion.

```cpp
bool search(string word, int i, node* cur){
  // recursive version of the search
  if (i >= word.length())
      return cur->end;
  if (cur->next.count(word[i]))
      return search(word,i+1,cur->next[word[i]]);
  // handling the dot wildcard
  if (word[i] == '.'){
      if (cur->next.size() == 0) 
          return false;
      bool found = false;
      for(auto& ch : cur->next)
        found = found | search(word,i+1,ch.second); 
      return found;
  }
  return false;
}
```
Note that we are using `cur->next.count()` since this does
not create a mapping if one doesn't already exist. 





