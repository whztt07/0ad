#include "precompiled.h"
#include "EventHandlers.h"
#include "Entity.h"

CEventAttack::CEventAttack( CEntity* target ) : CScriptEvent( L"attack", EVENT_ATTACK, true )
{
	m_target = target;
	AddLocalProperty( L"target", &m_target );
}

CEventGather::CEventGather( CEntity* target ) : CScriptEvent( L"gather", EVENT_GATHER, true )
{
	m_target = target;
	AddLocalProperty( L"target", &m_target );
}

CEventHeal::CEventHeal( CEntity* target ) : CScriptEvent( L"heal", EVENT_HEAL, true)
{
	m_target = target;
	AddLocalProperty( L"target", &m_target );
}

CEventGeneric::CEventGeneric( CEntity* target, int action ) : CScriptEvent( L"generic", EVENT_GENERIC, true)
{
	m_target = target;
	m_action = action;
	AddLocalProperty( L"target", &m_target );
	AddLocalProperty( L"action", &m_action );
}

/*CEventDamage::CEventDamage( CEntity* inflictor, CDamageType* damage ) : CScriptEvent( L"takesDamage", EVENT_DAMAGE, true )
{
	m_inflictor = inflictor;
	m_damage = damage;
	AddLocalProperty( L"inflictor", &m_inflictor, true );
	AddLocalProperty( L"damage", &m_damage );
}*/

CEventTargetChanged::CEventTargetChanged( CEntity* target ) : CScriptEvent( L"targetChanged", EVENT_TARGET_CHANGED, false )
{
	m_target = target;
	m_defaultOrder = -1;
	m_defaultAction = 0;
	m_defaultCursor = L"arrow-default";
	
	m_secondaryOrder = -1;
	m_secondaryAction = 0;
	m_secondaryCursor = L"arrow-default";
	

	AddLocalProperty( L"target", &m_target, true );
	AddLocalProperty( L"defaultOrder", &m_defaultOrder );
	AddLocalProperty( L"defaultAction", &m_defaultAction );
	AddLocalProperty( L"defaultCursor", &m_defaultCursor );
	AddLocalProperty( L"secondaryOrder", &m_secondaryOrder );
	AddLocalProperty( L"secondaryCursor", &m_secondaryCursor );
	AddLocalProperty( L"secondaryAction", &m_secondaryAction );
}

CEventPrepareOrder::CEventPrepareOrder( CEntity* target, int orderType ) : CScriptEvent( L"prepareOrder", EVENT_PREPARE_ORDER, true )
{
	m_target = target;
	m_orderType = orderType;
	AddLocalProperty( L"target", &m_target, true );
	AddLocalProperty( L"orderType", &m_orderType, true );
}

CEventOrderTransition::CEventOrderTransition( int orderPrevious, int orderCurrent, CEntity*& target, CVector3D& worldPosition ) : CScriptEvent( L"orderTransition", EVENT_ORDER_TRANSITION, true )
{
	m_orderPrevious = orderPrevious;
	m_orderCurrent = orderCurrent;
	m_target = &target;
	m_worldPosition = &worldPosition;
	AddLocalProperty( L"orderPrevious", &m_orderPrevious, true );
	AddLocalProperty( L"orderCurrent", &m_orderCurrent );
	AddLocalProperty( L"target", m_target );
	AddLocalProperty( L"position", m_worldPosition );
}
CEventNotification::CEventNotification( CEntityOrder order, uint type ) : CScriptEvent( L"notification", EVENT_NOTIFICATION, true )
{
	m_type = type;
	m_target = order.m_data[0].entity;
	m_data = (uint) order.m_data[1].data;
	CVector3D convert( order.m_data[0].location.x, 0.0f, order.m_data[0].location.y );
	m_location = convert;
	
	AddLocalProperty( L"type", &m_type );
	AddLocalProperty( L"target", &m_target );
	AddLocalProperty( L"data", &m_data );
	AddLocalProperty( L"location", &m_location );
}
