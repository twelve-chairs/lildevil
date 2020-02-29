cask 'lildevil' do
  version ':latest'
  sha256 :no_check

  url "https://gitlab.com/twelvechairssoftware/lildevil/-/raw/a23b274df64d348ab1def821d1ff28e07f1cd77a/dist/homebrew/lildevil.zip?inline=false"
  name 'lilDevil'
  homepage 'https://gitlab.com/twelvechairssoftware/lildevil'

  app 'lilDevil.app'
end
