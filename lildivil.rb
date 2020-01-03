class LilDevil < Formula
  desc "The Dev Tools Dashboard"
  homepage "https://gitlab.com/twelvechairssoftware/lildevil"
  version "0.0.1"


  url "https://gitlab.com/twelvechairssoftware/lildevil/bin/darwin", :using => :curl

  def install
    bin.install "twelvechairssoftware/lildevil"
  end
end