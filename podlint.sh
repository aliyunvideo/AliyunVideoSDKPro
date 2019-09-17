
git add .
git commit -m $1
git push
git tag -d $1
git push origin :refs/tags/$1
git tag $1
git push --tags

# pod spec lint --verbose --allow-warnings
# pod spec lint --sources=git@10.211.55.3:gitrepos/SYBaseSpec.git,https://github.com/CocoaPods/Specs --verbose --allow-warnings
#pod spec lint --sources=git@10.211.55.3:gitrepos/SYBaseSpec,https://github.com/CocoaPods/Specs.git --verbose --allow-warnings

#pod repo push SYBaseSpec *.podspec --allow-warnings
