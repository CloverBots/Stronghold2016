#include <Commands/SetTapeSpeed.h>
#include "OI.h"
#include "Commands/SetShooterSpeed.h"
#include "Commands/SetRopeSpeed.h"
#include "Commands/AlignWithGoal.h"

OI::OI()
{
	m_pContoursTable = NetworkTable::GetTable("GRIP/myContoursReport");

	CameraServer::GetInstance()->StartAutomaticCapture("cam1");
	CameraServer::GetInstance()->SetQuality(75);

	m_pUSBCamera.reset(new USBCamera("cam1", true));
	m_pUSBCamera->SetFPS(15.0);
	m_pUSBCamera->SetSize(160, 120);

	m_pStickyDrive.reset(new Joystick(0));
	m_pStickyShoot.reset(new Joystick(1));

	m_pStartButton.reset(new JoystickButton(m_pStickyShoot.get(), 8));
	m_pBackButton.reset(new JoystickButton(m_pStickyShoot.get(), 7));
	m_pAButton.reset(new JoystickButton(m_pStickyShoot.get(), 1));
	m_pBButton.reset(new JoystickButton(m_pStickyShoot.get(), 2));
	m_pXButton.reset(new JoystickButton(m_pStickyShoot.get(), 3));
	m_pYButton.reset(new JoystickButton(m_pStickyShoot.get(), 4));

	m_pStartButton->WhenPressed(new SetTapeSpeed(-0.25f));
	m_pStartButton->WhenReleased(new SetTapeSpeed(0.0f));

	m_pBackButton->WhenPressed(new SetRopeSpeed(-1.0f));
	m_pBackButton->WhenReleased(new SetRopeSpeed(0.0f));

	m_pAButton->WhenPressed(new SetShooterSpeed(-1.0f));
	m_pAButton->WhenReleased(new SetShooterSpeed(0.0f));

	m_pBButton->WhenPressed(new SetShooterSpeed(-0.5f));
	m_pBButton->WhenReleased(new SetShooterSpeed(0.0f));

	m_pXButton->WhenPressed(new AlignWithGoal());

	m_pYButton->WhenPressed(new SetShooterSpeed(0.75f));
	m_pYButton->WhenReleased(new SetShooterSpeed(0.0f));
}

std::vector<double> OI::GetContourValue(std::string value)
{
	return m_pContoursTable->GetNumberArray(value, llvm::ArrayRef<double>());
}

std::shared_ptr<Joystick> OI::GetStickyDrive()
{
	return m_pStickyDrive;
}

std::shared_ptr<Joystick> OI::GetStickyShoot()
{
	return m_pStickyShoot;
}

int OI::GetCameraXRes() const
{
	return m_CAMERA_X_RES;
}

int OI::GetCameraYRes() const
{
	return m_CAMERA_Y_RES;
}
