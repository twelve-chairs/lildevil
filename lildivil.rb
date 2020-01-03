class LilDevil < Formula
  desc "The Dev Tools Dashboard"
  homepage "https://bitbucket.org/user/repo"


  url "https://gitlab.com/twelvechairssoftware/lildevil", :using => :curl

  def install
    bin.install "twelvechairssoftware/lildevil"
  end
end