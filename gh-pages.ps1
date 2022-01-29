Set-Location .\docs
.\make.bat html
Set-Location ..
git checkout gh-pages
Remove-Item .\_sources .\_static
Move-Item .\docs\build\html\* -Force .
Remove-Item -Recurse .\docs
git add .
git commit -m "Rebuild documentation"
git checkout main
