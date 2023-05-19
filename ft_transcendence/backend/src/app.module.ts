import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { TypeOrmModule } from '@nestjs/typeorm';

// host: postgres --> has to be the name of the container
// and not localhost.
@Module({
  imports: [
    TypeOrmModule.forRoot({
      type: 'postgres',
      host: 'postgres',
      port: 5432,
      username: 'admin',
      password: 'admin',
      database: 'postgres',
      entities: [],
      synchronize: true,
      autoLoadEntities: true,
    })
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
