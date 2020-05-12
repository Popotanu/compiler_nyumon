#!/bin/bash
set -u
assert() {
  expected="$1"
  input="$2"

  ./tanucc "$input" > tmp.s
  cc -o tmpp tmp.s
  ./tmpp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $actual expected, but got $actual"
    exit 1
  fi
}


assert 0 0
assert 42 42
assert 21 "5+20-4"

echo OKtanu◎
