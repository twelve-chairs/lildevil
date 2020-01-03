class LilDevil < Formula
  desc "The Dev Tools Dashboard"
  homepage "https://gitlab.com/twelvechairssoftware/lildevil"
  version ""
  sha256 ""

  url "https://gitlab.com/twelvechairssoftware/lildevil/dist/homebrew", :using => :curl

  def install
    bin.install "twelvechairssoftware/lildevil"
  end
end