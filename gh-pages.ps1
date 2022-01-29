# Rebuild docs
Set-Location .\docs
.\make.bat html
Set-Location ..

# Switch to gh-pages
# docs\build\html will still be there because it is untracked
git checkout gh-pages

# Remove these so that we can move the new ones to the same paths
Remove-Item .\_sources -Recurse
Remove-Item .\_static -Recurse

# Move everything to the root directory
Move-Item .\docs\build\html\* -Force .

# Delete the docs directory
Remove-Item -Recurse .\docs

# Add, commit and return to main
git add .
git commit -m "Rebuild documentation"
git checkout main
