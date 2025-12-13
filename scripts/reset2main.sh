#!/bin/bash
cp -v score.csv /tmp/
git add .
git commit -am bork
git checkout main
cp -v /tmp/score.csv ./
git commit -am 'adding score'
