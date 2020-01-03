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
    system "ls", "la"
    system "unzip", "lildevil.zip"
    system "cp", "lilDevil.app", "~/Applications"
    # system "cmake", ".", *std_cmake_args
  end

end
