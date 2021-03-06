/*
 * Copyright (c) 2021 Yuriy Lisovskiy
 */

#pragma once

// xalwart
#include <xalwart.orm/repository.h>
#include <xalwart/conf/module.h>

// oauth-service
#include "./services/interfaces.h"
#include "../oauth/services/interfaces.h"


class UsersModuleConfig : public xw::conf::ModuleConfig
{
public:
	explicit inline UsersModuleConfig(
		const std::string& registration_name, xw::conf::Settings* settings
	) :
		xw::conf::ModuleConfig(registration_name, settings)
	{
	}

	void configure() override;

	void urlpatterns() override;

private:
	std::shared_ptr<xw::orm::Repository> _repository = nullptr;
	std::shared_ptr<IUserService> _user_service = nullptr;
	std::shared_ptr<IClientService> _client_service = nullptr;
};
