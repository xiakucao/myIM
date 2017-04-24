#include "login.h"
#include "link.h"
#include "myStruct.h"
#include <QMessageBox>

login::~login()
{
}

login::login(QWidget *parent): QDialog(parent)
{
	//初始化
	ui.setupUi(this);
}

//动态切换语言
//void login::changeEvent(QEvent *e)
//{
//	QDialog::changeEvent(e);
//	switch (e->type())
//	{
//	case QEvent::LanguageChange:
//		ui.retranslateUi(this);
//	default:
//		break;
//	}
//}

void login::login_accept() {
	//身份验证
	bool temp = false;
	struct logInf identify;
	identify.user = ui.user_lineEdit->text();
	identify.passwd = ui.passwd_lineEdit->text();
	temp = link::identifyConfirmation(identify);
	if (!temp) {
		QMessageBox::warning(NULL, "Error", "Password and user name do not match");
	}
	else {
		//建立连接，进入主界面
		accept();
	}
}

void login::register_accept()
{

}

void login::userStatus_accept()
{

}
