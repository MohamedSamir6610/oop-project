<?php
class RegisterModel {
    public $regUser;
    public $regPass;
    public $accountFlag;
    public function __construct() {
        $this->accountFlag = 0;
        $this->regUser = "";
        $this->regPass = "";
    }
}
?>
