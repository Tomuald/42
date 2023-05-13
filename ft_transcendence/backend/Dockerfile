FROM node:18-alpine

WORKDIR /usr/src/backend

#COPY . .

RUN npm i -g @nestjs/cli

RUN npm ci --omit=dev

RUN npm run build

RUN npm install pm2 -g

USER node

EXPOSE 3000

CMD ["pm2-runtime", "npm", "--", "run", "start:prod"]
#CMD ["npm", "run", "start:prod"]