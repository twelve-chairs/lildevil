# Documentation: https://docs.brew.sh/Formula-Cookbook
#                https://rubydoc.brew.sh/Formula
# PLEASE REMOVE ALL GENERATED COMMENTS BEFORE SUBMITTING YOUR PULL REQUEST!
class Lildevil < Formula
  desc "lildevil"
  homepage "https://gitlab.com/twelvechairssoftware/lildevil"
  url "https://gitlab.com/twelvechairssoftware/lildevil/raw/master/dist/homebrew/lildevil.zip"
  version "0.0.1"
  sha256 "7a679a9bfc6fd272aaccb16b57ee8d6cf3929fe1fba2447597eeecf48c105a42"

  # depends_on "cmake" => :build

  def install
    # ENV.deparallelize  # if your formula fails when building in parallel
    # Remove unrecognized options if warned by configure
    system "ls", "-la"
    system "unzip", "lildevil.zip"
    system "cp", "lilDevil.app", "~/Applications"
    # system "cmake", ".", *std_cmake_args
  end

  test do
    # `test do` will create, run in and delete a temporary directory.
    #
    # This test will fail and we won't accept that! For Homebrew/homebrew-core
    # this will need to be a test that verifies the functionality of the
    # software. Run the test with `brew test lildevil`. Options passed
    # to `brew install` such as `--HEAD` also need to be provided to `brew test`.
    #
    # The installed folder is not in the path, so use the entire path to any
    # executables being tested: `system "#{bin}/program", "do", "something"`.
    system "false"
  end
end
