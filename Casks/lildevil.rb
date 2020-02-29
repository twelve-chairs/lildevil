cask 'lildevil' do
  version ':latest'
  sha256 :no_check

  url "https://gitlab.com/twelvechairssoftware/lildevil/tree/master/dist/homebrew/lildevil.zip"
  name 'lilDevil'
  homepage 'https://gitlab.com/twelvechairssoftware/lildevil'

  app 'lilDevil.app'
end
