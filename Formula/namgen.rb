class Namgen < Formula
  desc "Ultra-fast fantasy and sci-fi name generator CLI & C++ library"
  homepage "https://github.com/joshuacox/namgen"
  url "https://github.com/joshuacox/namgen/archive/refs/tags/v0.3.0.tar.gz"
  license "Apache-2.0"
  head "https://github.com/joshuacox/namgen.git", branch: "main"

  depends_on "cmake" => :build

  def install
    system "cmake", "-S", ".", "-B", "build", *std_cmake_args
    system "cmake", "--build", "build"
    system "cmake", "--install", "build"
  end

  test do
    assert_match "Usage:", shell_output("#{bin}/namgen -h")
    assert_predicate bin/"namgen", :exist?
    assert_predicate bin/"namgen", :executable?
    output = shell_output("#{bin}/namgen -c 1").strip
    refute_empty output
  end
end
