/** @type {import('next').NextConfig} */
const nextConfig = {
  transpilePackages: ['namgen.js'],
  images: {
    unoptimized: true,
  },
};

export default nextConfig;
