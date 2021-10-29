# Sorting

```
// suppose we want to sort a vector of strings
vector<string> v;

// to sort in ascending order
// we can use stable_sort as well
sort(v.begin(),v.end());

// to sort in descending order (replace string with the appropriate type)
sort(v.begin(),v.end(),greater<string>()) 

// to do custom sort using lambda, e.g. this converts the string to lowercase
// before comparing
sort(v.begin(),v.end(),[](const string& a, const string& b) -> bool {
  string lowa = ""; for(char c : a) lowa += tolower(c);
  string lowb = ""; for(char c : b) lowb += tolower(c);
  return lowa < lowb;
});

```
