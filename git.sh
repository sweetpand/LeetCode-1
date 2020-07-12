#! /bin/sh
git checkout --orphan tmp
git add .
git commit -m 'Initialize LeetCode'
git branch -D master
git branch -m master
git push origin master --force