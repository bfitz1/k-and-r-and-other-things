# Test word-count by throwing a bunch of shit at it.
# It'll probably blow up on Unicode.

echo "Running word-count on c files in this directory"

FAILED=0
for file in *.c; do
    result=$(cat "$file" | ./bin/word-count)
    if [ $? -eq 0 ]; then
        echo "    $file succeeded with \"$result\""
    else
        echo "    $file failed with exit code $?"
        FAILED=1
    fi
done

if [ $FAILED -ne 1 ]; then
    echo "All examples seem like they're working. Good news!"
fi
