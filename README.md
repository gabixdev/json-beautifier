# json-beautifier

Extremely lightweight, simple and fast JSON beautifier for large files written in C.

- Doesn't load entire JSON file to memory, everything is done while streaming from stdin. **Note that JSON syntax isn't checked so passing invalid JSON data into this program may result in unpredictable results!**
- Works well with huge JSON files (even 100+ GB).
- Speed limited by i/o.
- Under 80 lines of C code.
- No dependencies.
- Licensed under WTFPL so do anything you want ¯\\\_(ツ)_/¯

## Compiling

```
make
```

As simple as that.

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
