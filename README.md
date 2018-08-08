# json-beautifier

Extremely lightweight, simple and fast JSON beautifier for large files written in C++.

- Doesn't load entire JSON file to memory, everything is done while streaming from stdin. **Note that JSON syntax isn't checked so passing invalid JSON data into this program may result in unpredictable results!**
- Works well with huge JSON files (even 100+ GB).
- Speed limited by i/o.
- Under 100 lines of C++ code.
- No dependencies (except STL).
- Licensed under WTFPL so do anything you want ¯\\\_(ツ)_/¯

## Compiling

**With CMake:**

```
mkdir build
cd build
cmake ..
make
```

...or if you are Windows user try CMake GUI.

**Without CMake:**

Linux/macOS/Other Unixes:
```
g++ -o beautify src/beautify.cpp
```
(or if you want use `clang++`)

Windows:

- Open Visual Studio prompt

```
cl /EHsc src\beautify.cpp /link /out:beautify.exe
```

## Usage

**Beautify some JSON from stdin and print it into stdout:**
```
echo '{"test":"test : tests \\\\test \\"test",["simple",\n"as",\n"that"]}' | ./beautify
```
Output:
```
{
    "test": "test : tests \\test \"test",
    [
        "simple",
        "as",
        "that"
    ]
}
```

**Beautify some JSON file and print it into stdout:**
```
cat test.json | ./beautify
```

**Beautify some JSON file and save it as `beautified.json`:**
```
cat test.json | ./beautify > beautified.json
```