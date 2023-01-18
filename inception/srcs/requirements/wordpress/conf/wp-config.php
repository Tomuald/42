<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wordpress_user' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
/** define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
/** define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
/** define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'RKEyX5g{,_9x}}K+[KV3Q$oz.uV~@#oWZXugOl>-28-B%9e/gF1J3_ho}8z;H;SM');
define('SECURE_AUTH_KEY',  '^~sh5gF=|]rP9(Zt3KW:_9r~t$~Y5u^89-]$yl#8MlM5`#+|l[1J6)6=<5H&eF+^');
define('LOGGED_IN_KEY',    'OFePY%_Ixg7TLnPw1tiTQ.!Eg1l](6&U:0|I5B} ]}st04:qphvZ8:bqzU+A),b*');
define('NONCE_KEY',        'Ey5e]dP`jboUGj||+JT-P5t`-ck?16G_T+Jo^nIv(KKT*jaYFk+),vz@w&Z`~sly');
define('AUTH_SALT',        '+)c#PJy@B7hq4?7s2wJ38>5txak*CIhH`T`R4+ue5~KKyP_N/Okj7T7bKFIqA@OU');
define('SECURE_AUTH_SALT', 'lsXb)&7+&k;5U>lT-5O6,8SH[gW_EMqwnW~33|j^B}U!mc|u@8]3=_IrI]b8Sbe2');
define('LOGGED_IN_SALT',   'j>S%Za9(V|,m|v,a]Ap%<aRK{?@e>gYrucp]}l1t#}y%U^cN +es:avV!$rBT,$h');
define('NONCE_SALT',       '+b,/[9#&m?hPAjxEwX=2n70Z-+L)Rp$Lny(B-UXX(`9]>n>NHkj|<oXR?-jZ(=0l');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
