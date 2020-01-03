
git add .
git commit -m $1
git pull
git push
git tag -d $1
git push origin :refs/tags/$1
git tag $1
git push --tags

