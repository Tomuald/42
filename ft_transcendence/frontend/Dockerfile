# Use a lightweight Node.js image
FROM node:18

# Set the working directory
WORKDIR /app

# Copy the package.json and package-lock.json files to the container
COPY package*.json ./

# Install dependencies
RUN npm install
RUN npm install axios

# Copy the rest of the application code to the container
COPY . .

# Build the application
RUN npm run build

# Expose port 8080 to the outside world
EXPOSE 8080

# Start the HTTP server to serve the built files
CMD ["npm", "run", "serve"]
