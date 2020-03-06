$name = 'Package Name'
$installerType = 'exe'
$url  = 'https://gitlab.com/twelvechairssoftware/lildevil/dist/choco/installer.exe'
$silentArgs = '/VERYSILENT'

Install-ChocolateyPackage $name $installerType $silentArgs $url