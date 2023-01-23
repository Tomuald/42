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
define( 'DB_USER', 'tgarriss' );

/** Database password */
define( 'DB_PASSWORD', 'password' );


define('FS_METHOD', 'direct');

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

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
define('AUTH_KEY','?x|uo#rHQFcr{-$:P+NNlm9j}(nh9tuR1*ebl/z-&+ h7hhZ= N!uu9L]/r|F4A_');
define('SECURE_AUTH_KEY', 'dL{$KWOCQ5k+-CVy19/Vc3b-7C.Cz=DCjK$qI2gIb|zv}JF8;H59VCh+4NDJd.Dh');
define('LOGGED_IN_KEY', '/aIyl{uCX~wxkY|,gb1.BT/+-1|Uj`&5@3NTK p]UJf:D4h+]L;T:W=olyt8^ULg');
define('NONCE_KEY', '>>0q{$GF[{,m(Sf!!%xtp2m5<j-d-$_J})%F8Q${&GyuM.f LrEh5P#`|dhWLCny');
define('AUTH_SALT', '_o|BHdPs.[N>c,AVR_/;=qI2$b1qVy,Z2,$tG#=|@D4i`8lZGC&yv$;M}3gjC_2,');
define('SECURE_AUTH_SALT', '|d4(Q?<zrQe|Sz$Hc#sJ6|].Lv.zqe2.+{S: !j,vJ^x1-gRF<B>0*3rU2(nsYj|');
define('LOGGED_IN_SALT', '9epe[S--SnMi)^nWlu5aKF-7_o+%2:m}c-tb/XGy$Tu6-&iC8L.5Hfy6XVx<Nz_Q');
define('NONCE_SALT', 'yV; }=fHE{! )U`L:]!&B{oDF1j(^$dM]bAo_^-v)E|a2QkSfyqVu|z]|OJ2-ewO');

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
