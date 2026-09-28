/** @type {import('next').NextConfig} */
const isGithubPages = process.env.GITHUB_PAGES === 'true';

const nextConfig = {
  output: 'export',
  basePath: process.env.NEXT_PUBLIC_BASE_PATH || (isGithubPages ? '/namgen' : ''),
  images: {
    unoptimized: true,
  },
  trailingSlash: true,
};

export default nextConfig;
