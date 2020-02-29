cask 'lildevil' do
  version ':latest'
  sha256 :no_check

  url "https://gitlab.com/twelvechairssoftware/lildevil/-/raw/master/dist/homebrew/lildevil.zip?inline=false"
  name 'lilDevil'
  homepage 'https://gitlab.com/twelvechairssoftware/lildevil'

  app 'lilDevil.app'
end
