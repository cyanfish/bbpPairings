{
  description = "Compute swiss pairings";

  inputs = { nixpkgs.url = "github:NixOS/nixpkgs"; };

  outputs = { self, nixpkgs }: {

    packages.x86_64-linux.default =
      with import nixpkgs { system = "x86_64-linux"; };
      stdenv.mkDerivation {
        name = "bbpPairings";
        src = ./.;
        nativeBuildInputs = [ pkgs.gcc ];

        buildPhase = ''
          make
        '';

        installPhase = ''
          mkdir -p $out/bin
          cp bbpPairings.exe $out/bin/bbpPairings
        '';
      };
  };
}
