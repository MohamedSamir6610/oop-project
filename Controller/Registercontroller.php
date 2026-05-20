<?php
require_once '../Model/RegisterModel.php';
session_start();

class RegisterController {
    public function processRegister() {
        $inputUser = $_POST['inputUser'];
        $inputPass = $_POST['inputPass'];

      
        $model = new RegisterModel();
        
        $model->regUser = $inputUser;
        $model->regPass = $inputPass;
        $model->accountFlag = 1;
        $_SESSION['regUser'] = $model->regUser;
        $_SESSION['regPass'] = $model->regPass;
        $_SESSION['accountFlag'] = $model->accountFlag;

        echo "Registration successful! You can now go to Book Appointment page.";
    }
}


$controller = new RegisterController();
$controller->processRegister();
?>
