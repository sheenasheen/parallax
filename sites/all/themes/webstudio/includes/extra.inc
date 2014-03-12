<?php
/**
 * Extra Class
 * TODO:
 *
 * @package default
 * @author
 **/
class extra{


  //
  // Prepared from the http://www.mendoweb.be/blog/php-convert-string-to-camelcase-string
  //
  public static function camelCase( $str,$exclude = array(),$first_Upper = TRUE )
  {
    // replace accents by equivalent non-accents
    $str = self::replaceAccents($str);
    // non-alpha and non-numeric characters become spaces
    $str = preg_replace('/[^a-z0-9' . implode("", $exclude) . ']+/i', ' ', $str);
    // uppercase the first character of each word
    $str = ucwords(trim($str));

    if ($first_Upper) {
      return str_replace(" ", "", $str);
    } else {
      return lcfirst(str_replace(" ", "", $str));
    }

  }

  public static function replaceAccents($str) {
      $search = explode(",",
  "ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,ø,Ø,Å,Á,À,Â,Ä,È,É,Ê,Ë,Í,Î,Ï,Ì,Ò,Ó,Ô,Ö,Ú,Ù,Û,Ü,Ÿ,Ç,Æ,Œ");
      $replace = explode(",",
  "c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,o,O,A,A,A,A,A,E,E,E,E,I,I,I,I,O,O,O,O,U,U,U,U,Y,C,AE,OE");
      return str_replace($search, $replace, $str);
  }

  // public function getGitHash($path="",$length=7)
  // {
  //   if (!$path) {
  //     return FALSE;
  //   }

  //   try {
  //     if (!file_exists($path)) {
  //        throw new Exception('Git repo does not exist!');
  //     }
  //     $handle = fopen($path, 'r');
  //     $data = fread($handle,filesize($path));
  //     fclose($handle);
  //     $output = substr($data, 0, $length);
  //     return $output;

  //   } catch (Exception $e) {
  //     // drupal_set_message($e->getMessage(), 'error', FALSE);
  //     return $e->getMessage();
  //   }

  // }

  // public function getGitLog()
  // {

  //   try {

  //     if (!shell_exec("git rev-parse --abbrev-ref HEAD") ) {
  //       throw new Exception('Git repo does not exist!');
  //     }

  //     $branch = shell_exec("git rev-parse --abbrev-ref HEAD");
  //     $hash   = shell_exec("git log -1 --pretty=format:'%h' ");
  //     // $output = $branch.'-'.$hash;
  //     $output = array(
  //       'branch' => $branch,
  //       'hash'   => $hash
  //     );
  //     return $output;

  //   } catch (Exception $e) {
  //     return $e->getMessage();
  //   }


  // }

} // END class
