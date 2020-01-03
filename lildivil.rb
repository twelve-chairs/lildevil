class LilDevil < Formula
  desc "The Dev Tools Dashboard"
  homepage "https://gitlab.com/twelvechairssoftware/lildevil"


  url "https://gitlab.com/twelvechairssoftware/lildevil/bin/darwin", :using => :curl

  def install
    bin.install "twelvechairssoftware/lildevil"
  end
end