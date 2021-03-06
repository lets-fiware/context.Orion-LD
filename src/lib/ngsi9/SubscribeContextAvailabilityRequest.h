#ifndef SRC_LIB_NGSI9_SUBSCRIBECONTEXTAVAILABILITYREQUEST_H_
#define SRC_LIB_NGSI9_SUBSCRIBECONTEXTAVAILABILITYREQUEST_H_

/*
*
* Copyright 2013 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Ken Zangelin
*/
#include <string>

#include "ngsi/StringList.h"
#include "ngsi/EntityIdVector.h"
#include "ngsi/Duration.h"
#include "ngsi/Reference.h"
#include "ngsi/Restriction.h"
#include "ngsi/SubscriptionId.h"
#include "rest/EntityTypeInfo.h"



/* ****************************************************************************
*
* SubscribeContextAvailabilityRequest - 
*
* NOTE
*   The field subscriptionId has been removed from this structure as
*   we believe it is an error in the OMA NGSI spec.
*   Appropriate actions will be taken as new intel arrives.
*
*   Rationale:
*     The client does not have the possibility of specifying ID in
*     the subscribeContextRequest (NGSI 10) nor in registerContext for
*     new registrations (NGSI9).
*     In both cases, the ID is generated by the NGSI server.
*/
typedef struct SubscribeContextAvailabilityRequest
{
  EntityIdVector         entityIdVector;    // Mandatory
  StringList             attributeList;     // Optional
  Reference              reference;         // Mandatory
  Duration               duration;          // Optional
  Restriction            restriction;       // Optional

  /* The number of restrictions */
  int                    restrictions;

  SubscribeContextAvailabilityRequest();
  std::string  render(void);
  std::string  check(const std::string& predetectedError);
  void         release(void);

  void         fill(EntityTypeInfo typeInfo);
} SubscribeContextAvailabilityRequest;

#endif  // SRC_LIB_NGSI9_SUBSCRIBECONTEXTAVAILABILITYREQUEST_H_
