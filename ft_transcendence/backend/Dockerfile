FROM node:18-alpine

WORKDIR /usr/src/backend

COPY . .

RUN npm i -g @nestjs/cli

RUN npm ci --omit=dev

RUN npm run build

RUN npm install @nestjs/typeorm pg typeorm
RUN npx typeorm init --database postgress --express

USER node

EXPOSE 3000


CMD ["npm", "--", "run", "start:prod"]
