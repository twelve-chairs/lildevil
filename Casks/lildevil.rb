cask 'lildevil' do
  version ':latest'
  sha256 :no_check

  url "https://github.com/twelvechairssoftware/lildevil/raw/master/dist/homebrew/lildevil.zip"
  name 'lilDevil'
  homepage 'https://github.com/twelvechairssoftware/lildevil'

  app 'lilDevil.app'
end
