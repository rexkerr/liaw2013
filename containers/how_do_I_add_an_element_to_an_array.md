## How Do I Add an Element to An Array?

The answer to this question depends on where you intend to add the
item.

To add an item at the end:

```c++
std::vector<int> v = { 1, 3, 4};

v.push_back(5);

// v is now:  1,3,4,5
```

To add it at the beginning:

```c++
v.insert(begin(v), 0);

// v is now:  0,1,3,4,5
```

To insert it somewhere in the middle:

```c++
v.insert(begin(v) + 2, 2);

// v is now:  0,1,2,3,4,5
```

