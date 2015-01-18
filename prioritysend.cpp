#include <znc/Client.h>
#include <znc/Modules.h>
#include <znc/IRCNetwork.h>
#include <znc/IRCSock.h>

class CPrioritySend : public CModule {
public:
	const CString MessagePrefix = "(p!)";
	
	MODCONSTRUCTOR(CPrioritySend) {}
	
	virtual EModRet OnUserNotice(CString& sTarget, CString& sMessage) override {
		if (!sMessage.TrimPrefix(MessagePrefix))
			return CONTINUE;
		
		CIRCSock* pIRCSock = GetNetwork()->GetIRCSock();
		
		if (!pIRCSock)
			return CONTINUE;
		
		pIRCSock->PutIRCQuick("NOTICE " + sTarget + " :" + sMessage);
		
		return HALT;
	}
	
	virtual EModRet OnUserMsg(CString& sTarget, CString& sMessage) override {
		if (!sMessage.TrimPrefix(MessagePrefix))
			return CONTINUE;
		
		CIRCSock* pIRCSock = GetNetwork()->GetIRCSock();
		
		if (!pIRCSock)
			return CONTINUE;
		
		pIRCSock->PutIRCQuick("PRIVMSG " + sTarget + " :" + sMessage);
		
		return HALT;
	}
};

NETWORKMODULEDEFS(CPrioritySend, "Allows certain messages to be placed in front of the send queue")
