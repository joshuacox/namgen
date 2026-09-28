class Namgen < Formula
  desc "Flexible combinator and procedural fantasy/sci-fi name generator"
  homepage "https://joshuacox.github.io/namgen/"
  url "https://github.com/joshuacox/namgen/archive/refs/tags/v1.0.0.tar.gz"
  sha256 "PLACEHOLDER_SHA256"
  license "MIT"
  head "https://github.com/joshuacox/namgen.git", branch: "main"

  def install
    system "make", "all"
    bin.install "namgen"
    man1.install "man/namgen.1"
    pkgshare.install "assets"
    bash_completion.install "completions/namgen.bash" => "namgen"
    zsh_completion.install "completions/_namgen" => "_namgen"
    fish_completion.install "completions/namgen.fish" => "namgen.fish"
  end

  test do
    system "#{bin}/namgen", "-c", "3", "-S", "42"
    system "#{bin}/namgen", "--fantasy-dragons", "-c", "1", "--json"
  end
end
